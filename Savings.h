//
//  Savings.h
//  AirgeadBank
//
//  Created by Dathan Pompa on 10/6/23.
//
#ifndef SAVINGS_H_
#define SAVINGS_H_
//
// creates Savings header file
class Savings
{
    // makes data private within object
private:
    double initialInvestment;
    double monthlyDeposit;
    double interestRate;
    int numOfYears;
    
    //allows obj and methods to be accessed
public:
    Savings(double investment, double monthDep, int years, double rate);
    virtual ~Savings();
    void withMonthlyDeposit();
    void noMonthlyDeposit();
    void formatTable();
};

#endif /* Savings_h */
