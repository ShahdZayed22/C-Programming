#include <stdio.h>

int main()
{
    float total_price = 0, TotatWithShipping = 0, TotalWithDiscount = 0;
    int shipping = 0, product, count = 0;
    char decision;
    char* cart[100];  // Stores selected items for display

    // Display product list
    printf("Welcome To Our Online Shop!\nHere is our products list:\n\n");
    printf("************************************\n");
    printf("1-  Chips ---------------> 05.0$\n");
    printf("2-  Yogurt -------------> 03.0$\n");
    printf("3-  Milk ----------------> 07.0$\n");
    printf("4-  Instant Coffee ------> 15.0$\n");
    printf("5-  Coke ----------------> 10.0$\n");
    printf("6-  Biscuits ------------> 02.5$\n");
    printf("7-  Cake ----------------> 03.5$\n");
    printf("8-  Juice ---------------> 06.5$\n");
    printf("9-  Chocolate -----------> 07.5$\n");
    printf("10- Noodles -------------> 05.0$\n");
    printf("************************************\n\n");

    // Shopping loop
    do
    {
        printf("Enter item number to add to cart: ");
        scanf("%d", &product);

        switch (product) {
            case 1: cart[count] = "Chips ---> 5.0$"; total_price += 5.0; break;
            case 2: cart[count] = "Yogurt --- 3.0$"; total_price += 3.0; break;
            case 3: cart[count] = "Milk ---> 7.0$"; total_price += 7.0; break;
            case 4: cart[count] = "Instant Coffee --- 15.0$"; total_price += 15.0; break;
            case 5: cart[count] = "Coke ---> 10.0$"; total_price += 10.0; break;
            case 6: cart[count] = "Biscuits ---> 2.5$"; total_price += 2.5; break;
            case 7: cart[count] = "Cake ---> 3.5$"; total_price += 3.5; break;
            case 8: cart[count] = "Juice ---> 6.5$"; total_price += 6.5; break;
            case 9: cart[count] = "Chocolate ---> 7.5$"; total_price += 7.5; break;
            case 10: cart[count] = "Noodles ---> 5.0$"; total_price += 5.0; break;
            default: 
                printf("Invalid item! Choose again.\n"); 
                continue; 
        }
        count++;

        printf("Cart total: %.1f$\n", total_price);
        printf("Add another item? (Y/N): ");
        scanf(" %c", &decision);

        if ((count < 2) && (decision == 'n' || decision == 'N'))
        {
            printf("Minimum purchase is 2 items. Continue shopping.\n\n");
        }

    } while ((decision == 'y' || decision == 'Y') || (count < 2));

    // Shipping choice
    printf("Overnight shipping? (+5$) (Y/N): ");
    scanf(" %c", &decision);

    if (count >= 5) TotalWithDiscount = total_price * 0.8;
    else TotalWithDiscount = total_price;

    if (decision == 'y' || decision == 'Y') shipping = 5;
    else if (decision == 'n' || decision == 'N') shipping = (total_price < 10) ? 2 : 3;
    else printf("Invalid choice!\n");

    TotatWithShipping = TotalWithDiscount + shipping;

    // Receipt
    printf("*************** Receipt **************\n");
    for (int i = 0; i < count; i++) printf("- %s\n", cart[i]);

    if (count >= 5) {
        printf("Before discount: %.1f$\n", total_price);
        printf("After discount: %.1f$\n", TotalWithDiscount);
    } else printf("Price: %.1f$\n", total_price);

    printf("Shipping: %d$\n", shipping);
    printf("Total Price: %.1f$\n", TotatWithShipping);
    printf("************** Thank You! *************");

    return 0;
}
