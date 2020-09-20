class electricityBill {
private:
    int id;
    int units;
    double bill;

public:
    void set(int i, int u)
    {
        id = i;
        units = u;
    }
    double getBill()
    {
        return bill;
    }
    void calculateBill()
    {
        if(units > 250)
            bill = (50 * 0.5) + (100 * 0.75) + (100 * 1.2) + ((units - 250) * 1.5);
        else if(units > 150)
            bill = (50 * 0.5) + (100 * 0.75) + ((units - 150) * 1.2);
        else if(units > 50)
            bill = (50 * 0.5) + ((units - 50) * 0.75);
        else
            bill = units * 0.5;
    }
};
