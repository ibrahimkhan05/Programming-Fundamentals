#include <stdio.h>

int main(void) {
    float doge_coin = 1000.0f;             // Initial Dogecoin balance
    float increase_rate = 0.20f;           // 20% increase per week
    float profit_cash = 0.0f;              // Cash profit from sales
    float initial_worth_whole = 10.0f;     // Initial total worth in USD
    float one_coin_worth = 0.01f;          // Start with 1 cent per Dogecoin
    float increased_coin_worth, doge_coin_sell;

    for (int i = 1; i <= 52; i++) {  
        // Update the worth of one Dogecoin with a 20% increase
        one_coin_worth *= (1 + increase_rate);

        // Calculate total worth of all Dogecoin after the increase
        increased_coin_worth = one_coin_worth * doge_coin;

        // Calculate profit as the difference between increased value and previous total worth
        float profit = increased_coin_worth - initial_worth_whole;

        // Sell half of the profit and add it to cash reserve
        float profit_to_sell = profit / 2;
        profit_cash += profit_to_sell;

        // Calculate how much Dogecoin to sell for profit_to_sell amount in USD
        doge_coin_sell = profit_to_sell / one_coin_worth;

        // Deduct the sold Dogecoin from the total Dogecoin balance
        doge_coin -= doge_coin_sell;

        // Update initial_worth_whole to the new increased worth
        initial_worth_whole = increased_coin_worth;
    }
    
    // Report end-of-year results
    printf("End of Year Report:\n");
    printf("Total cash profit: $%.2f\n", profit_cash);
    printf("Remaining Dogecoin: %.2f\n", doge_coin);
    printf("One Dogecoin Worth: %.2f\n", one_coin_worth);
    printf("Total worth in USD: $%.2f\n", (doge_coin * one_coin_worth));

    return 0;
}
