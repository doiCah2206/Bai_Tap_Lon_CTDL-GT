#include <iostream>
#include "vector.cpp"
using namespace std;
class BigNumber
{

public:
    vector<int> BigNum;
    bool isPositive;
    BigNumber() { isPositive = true; }
    BigNumber(int x){
        if (x < 0){
            isPositive = false;
            x *= -1;
        }
        else{
            if (x == 0){
                BigNum.insert(0, 0);
            }
            isPositive = true;
        }
        while (x > 0){
            BigNum.insert(0, x % 10);
            x /= 10;
        }
    }
    void print(){
        if (isPositive == false){
            cout << "-";
        }
        for (int i = 0; i < BigNum.size(); i++){
            cout << BigNum[i];
        }
    }
    void pop_zero_front(){
        while (BigNum.size() != 1 && BigNum[0] == 0){
            BigNum.pop_front();
        }
    }
    BigNumber &operator=(const BigNumber &other){
        if (this != &other){
            this->BigNum = other.BigNum;
            this->isPositive = other.isPositive;
        }
        return *this;
    }
    // Nhan so lon voi 1 so kieu int
    BigNumber Mulx(int k){
        BigNumber Result;
        if (k == 0){
            int re = 0;
            Result.BigNum.insert(0, 0);
            return Result;
        }
        int rmd = 0;
        if ((k < 0 && isPositive == true) || (k > 0 && isPositive == false)){
            Result.isPositive = false;
        }
        k < 0 ? k *= -1 : k;
        for (vector<int>::reverse_iterator it = this->BigNum.rbegin(); it != this->BigNum.rend(); ++it){
            int re = k * (*it) + rmd;
            Result.BigNum.insert(0, re % 10);
            rmd = re / 10;
        }
        while (rmd > 0){
            Result.BigNum.insert(0, rmd % 10);
            rmd = rmd / 10;
        }
        return Result;
    }
    //Nhan 2 so lon
    BigNumber Mul(BigNumber &other){
        BigNumber Result;
        if ((BigNum.size() == 1 && BigNum[0] == 0) || (other.BigNum.size() == 1 && other.BigNum[0] == 0)){
            Result.BigNum.insert(0, 0);
            return Result;
        }
        // Tao Vector BigNum cho Result
        long n = BigNum.size();
        long m = other.BigNum.size();
        for (long i = 0; i < n + m; i++){
            Result.BigNum.push_back(0);
        }
        int temp = 0;
        for (long i = m - 1; i >= 0; i--){
            for (long j = n - 1; j >= 0; j--){
                int mul = other.BigNum[i] * BigNum[j] + temp + Result.BigNum[i + j + 1];
                Result.BigNum[i + j + 1] = mul % 10;
                temp = mul / 10;
            }
            Result.BigNum[i] += temp;
            temp = 0;
        }
        Result.pop_zero_front();
        Result.isPositive = (this->isPositive == other.isPositive);
        return Result;
    }
    // Cong Tru TH 1 + TH 2
    BigNumber Add_Sub_1_2(BigNumber &other){
        BigNumber Result;
        long n = this->BigNum.size();
        long m = other.BigNum.size();
        int temp = 0;
        while (n > 0 || m > 0 || temp > 0){
            int re = 0;
            if (n != 0){
                re += (this->BigNum[n - 1]);
                n--;
            }
            if (m != 0){
                re += other.BigNum[m - 1];
                m--;
            }
            re += temp;
            Result.BigNum.insert(0, re % 10);
            temp = re / 10;
        }
        if (!isPositive){
            Result.isPositive = false;
        }
        Result.pop_zero_front();
        return Result;
    }
    // So Sanh
    int Cmp(BigNumber &other){
        if (BigNum.size() != other.BigNum.size()){
            return BigNum.size() > other.BigNum.size() ? 1 : 0;
        }
        for (int i = 0; i < BigNum.size(); i++){
            if (BigNum[i] != other.BigNum[i]){
                return BigNum[i] > other.BigNum[i] ? 1 : 0;
            }
        }
        return -1;
    }
    // Cong Tru TH 3
    BigNumber Add_Sub_3(BigNumber &other){
        BigNumber Result;
        long n = BigNum.size();
        long m = other.BigNum.size();
        int temp = 0;
        while (n > 0){
            int add_sub = 0;
            if (m > 0){
                if (BigNum[n - 1] < (other.BigNum[m - 1] + temp)){
                    add_sub = BigNum[n - 1] + 10 - (other.BigNum[m - 1] + temp);
                    m--;
                    temp = 1;
                    Result.BigNum.insert(0, add_sub);
                    n--;
                    continue;
                }
                else{
                    add_sub = BigNum[n - 1] - (other.BigNum[m - 1] + temp);
                    m--;
                    temp = 0;
                    Result.BigNum.insert(0, add_sub);
                    n--;
                    continue;
                }
            }
            if (BigNum[n - 1] < temp){
                add_sub = BigNum[n - 1] + 10 - temp;
                Result.BigNum.insert(0, add_sub);
                temp = 1;
                n--;
            }
            else{
                add_sub = BigNum[n - 1] - temp;
                Result.BigNum.insert(0, add_sub);
                temp = 0;
                n--;
            }
        }
        Result.isPositive = isPositive;
        Result.pop_zero_front();
        return Result;
    }
    // Cong so lon
    BigNumber Add(BigNumber &other){
        if (isPositive && other.isPositive){

            return this->Add_Sub_1_2(other);
        }
        else if (!isPositive && !other.isPositive){
            return this->Add_Sub_1_2(other);
        }
        else{
            if (Cmp(other) == 1){
                return this->Add_Sub_3(other);
            }
            else if (Cmp(other) == 0){
                return other.Add_Sub_3(*this);
            }
            else{
                return this->Add_Sub_3(other);
            }
        }
    }
    // Tru so lon
    BigNumber Sub(BigNumber &other){
        BigNumber Result;
        if (isPositive && !other.isPositive){
            Result = this->Add_Sub_1_2(other);
            return Result;
        }
        else if (!isPositive && other.isPositive){
            Result = this->Add_Sub_1_2(other);
            return Result;
        }
        else{
            if (Cmp(other) == 1){
                Result = this->Add_Sub_3(other);
                return Result;
            }
            else if (Cmp(other) == 0){
                Result = other.Add_Sub_3(*this);
                if (isPositive == other.isPositive)
                    Result.isPositive = !isPositive;
                return Result;
            }
            else{
                Result.BigNum.insert(0, 0);
                return Result;
            }
        }
    }
};

int main(){
    //   Fibonacii
    cout << "Tinh so Fibonacci thu n: ";
    cout << "\nNhap n: ";
    int n;
    cin >> n;
    BigNumber A(0);
    BigNumber B(1);
    BigNumber Fib;
    if (n == 0){
        Fib = A;
    }
    else if (n == 1){
        Fib = B;
    }
    else if (n > 1){
        for (int i = 0; i < n - 1; i++){
            Fib = A.Add(B);
            A = B;
            B = Fib;
        }
    }
    cout << "So Fibonacci thu " << n << " la: ";
    Fib.print();
    //   Tinh Giai Thua
    cout<< endl << "Tinh Giai Thua :\n";
    cout << "Nhap m: ";
    int m;cin >> m;
    BigNumber GT(1);
    for (int i = 1; i <= m; i++){
        BigNumber temp(i);
        GT = GT.Mul(temp);
    }
    cout << m << "!" << " = ";
    GT.print();
    cout << endl;
    return 0;
}
