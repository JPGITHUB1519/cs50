    while (change > 0.0f) {
        change = greedyCoins(change);
        totalCoins++;
        printf("%f\n", change);

        if (totalCoins == 5) {
            break;
        }
    } 
    printf("%d\n", totalCoins);