#include <stdio.h>

// Function to display the product menu
void displayMenu() {
    printf("************************************\n");
    printf("1-  Chips ---------------> 05.0$\n");
    printf("2-  Yogurt -------------> 03.0$\n");
    printf("3-  Milk ----------------> 07.0$\n");
    printf("4-  Instant Coffee ------> 15.0$\n");
    printf("5-  Coke ----------------> 10.0$\n");
    printf("6-  Biscuits -------------> 02.5$\n");
    printf("7-  Cake ----------------> 03.5$\n");
    printf("8-  Juice ---------------> 06.5$\n");
    printf("9-  Chocolate -----------> 07.5$\n");
    printf("10- Noodles -------------> 05.0$\n");
    printf("************************************\n\n");
}

// Function to return the price of a selected item
float getItemPrice(int product) {
    switch (product) {
        case 1: return 5.0;
        case 2: return 3.0;
        case 3: return 7.0;
        case 4: return 15.0;
        case 5: return 10.0;
        case 6: return 2.5;
        case 7: return 3.5;
        case 8: return 6.5;
        case 9: return 7.5;
        case 10: return 5.0;
        default: return 0.0;
    }
}

// Function to calculate shipping cost
int getShippingCost(float total_price, char decision) {
    if (decision == 'Y' || decision == 'y') {
        return 5; // Overnight shipping
    } else {
        return (total_price < 10) ? 2 : 3;
    }
}

// Function to print the receipt
void printReceipt(float total_price, float TotalWithDiscount, int shipping, int itemCount) {
    printf("*************** Receipt **************\n");
    
    printf("Total Items: %d\n", itemCount);

    if (itemCount >= 5) {
        printf("Price BEFORE discount: %.1f$\n", total_price);
        printf("Price AFTER discount: %.1f$\n", TotalWithDiscount);
    } else {
        printf("Price: %.1f$\n", total_price);
    }

    printf("Shipping: %d$\n", shipping);
    printf("*************************************\n");
    printf("Total Price: %.1f$\n", TotalWithDiscount + shipping);
    printf("************** Thank You! *************\n");
}

int main() {
    float total_price = 0;
    float TotalWithDiscount = 0;
    int shipping = 0;
    char decision;
    int count = 0;
    int product;

    printf("Welcome To Our Online Shop!\nHere is our product list:\n\n");
    displayMenu();

    // Adding items loop
    do {
        printf("Enter item number: ");
        scanf("%d", &product);

        float price = getItemPrice(product);
        if (price == 0.0) {
            printf("Invalid choice. Please try again.\n");
            continue;
        }

        total_price += price;
        count++;

        printf("Cart total price: %.1f$\n", total_price);

        if (count < 2) {
            printf("Minimum purchase is 2 items. Please continue shopping.\n");
            continue;
        }

        printf("Do you want to add another item? (Y/N): ");
        scanf(" %c", &decision);

    } while (decision == 'Y' || decision == 'y');

    // Apply discount if purchasing 5 or more items
    TotalWithDiscount = (count >= 5) ? total_price * 0.8 : total_price;

    printf("Do you need overnight shipping? (Y/N): ");
    scanf(" %c", &decision);
    
    shipping = getShippingCost(total_price, decision);
    
    printReceipt(total_price, TotalWithDiscount, shipping, count);

    return 0;
}
