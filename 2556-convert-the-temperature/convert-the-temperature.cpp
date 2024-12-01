class Solution {
public:
    vector<double> convertTemperature(double celsius) {
        double fr = celsius*1.80 + 32.00;
        double kel = celsius +273.15;
        return {kel, fr};
    }
};