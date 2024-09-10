#include <stdio.h>

int main() {
    int customer_id;
    char customer_name;
    float units_consumed, total_amount; 

    printf("Enter Customer Name: ");
    scanf("%c", &customer_name);
    printf("Enter Customer ID: ");
    scanf("%d", &customer_id);
    printf("Enter Units Consumed: ");
    scanf("%f", &units_consumed);

    if (units_consumed <= 199) {
        total_amount = units_consumed * 16.20;
    } else if (units_consumed >= 200 && units_consumed < 300) {
        total_amount = units_consumed * 20.10;
    } else if (units_consumed >= 300 && units_consumed < 500) {
        total_amount = units_consumed * 27.10;
    } else {
        total_amount = units_consumed * 35.90;
    }
    
    if(total_amount > 18000){
    	printf("Surcharge of 15%% is applied.");
    	float Extra = total_amount * 0.15;
    	printf("\nElectricity Bill\n");
	    printf("-----------------\n");
	    printf("Customer ID   : %d\n", customer_id);
	    printf("Customer Name : %c\n", customer_name);
	    printf("Units Consumed: %.2f\n", units_consumed);
	    printf("Total Amount Before surcharge  : %.2f\n", total_amount);
    	total_amount += Extra;
    	printf("Total Amount after surcharge  : %.2f\n", total_amount);
	}
	else{
	    printf("\nElectricity Bill\n");
	    printf("-----------------\n");
	    printf("Customer ID   : %d\n", customer_id);
	    printf("Customer Name : %c\n", customer_name);
	    printf("Units Consumed: %.2f\n", units_consumed);
	    printf("Total Amount  : %.2f\n", total_amount);
	}

}