class StockSpanner {
public:
    stack<int> s;  // Stack to store the day indices
    vector<int> prices;  // Vector to store the prices as they arrive
    int day_index;  // Tracks the current day(starts at 0)

public:
    StockSpanner() {
        day_index = 0;
    }
    
    int next(int price) {
        // 1. Add the new price to our list
        prices.push_back(price);

        // 2. Clear out all smaller or equal elements
        while(s.size() > 0 && prices[s.top()] <= price) {
            s.pop();
        }

        // 3. Calculate the span
        int span;
        if(s.empty()) {
            span = day_index + 1;
        } else {
            span = day_index - s.top();  // prevHigh
        }

        // 4. Push current day index to stack and move to the next day
        s.push(day_index);
        day_index++;

        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */