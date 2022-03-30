#include <stdio.h>

int main()
{
    int totinvest =22500;//Total investment
    //value of each share 
    int value = 50;
    //discount on each share 
    int discount = ((double)10/100)*value;
    //Market price
    int mprice =value - discount;
    //total no.of shares purchased 
    int no_shares = totinvest/mprice;
    //total dividend
    int dividend = (double)12/100*value*no_shares;
    //rate of return 
    double retrnpercent = (double)dividend/totinvest*100;
    printf("No.of shares purchased = %d\n",no_shares);
    printf("Total dividend = %d\n",dividend);
    printf("Rate of return(approx to nearest integer) = %d\n",(int)retrnpercent);
    return 0;
}
