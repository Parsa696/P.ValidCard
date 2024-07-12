#include <iostream>
#include <string>
#include <map>

using namespace std;

// تابع اعتبارسنجی شماره کارت (با استفاده از الگوریتم Luhn)
bool isValidCardNumber(const string& cardNumber) {
    int sum = 0;
    bool alternate = false;
    for (int i = cardNumber.length() - 1; i >= 0; i--) {
        int n = cardNumber[i] - '0';
        if (alternate) {
            n *= 2;
            if (n > 9) {
                n -= 9;
            }
        }
        sum += n;
        alternate = !alternate;
    }
    return (sum % 10 == 0);
}

// تابع برای چاپ کارت با قالب مورد نظر
void printFormattedCard(const string& cardNumber) {
    cout << "CARD: ";
    for (int i = 0; i < cardNumber.length(); i++) {
        cout << cardNumber[i];
        if ((i + 1) % 4 == 0 && i != cardNumber.length() - 1) {
            cout << "-";
        }
    }
    cout << endl;
}

// تابع برای پیدا کردن بانک مربوطه
string findBank(const string& cardNumber, const map<string, string>& bankPrefixes) {
    string prefix = cardNumber.substr(0, 6);
    auto it = bankPrefixes.find(prefix);
    if (it != bankPrefixes.end()) {
        return it->second;
    } else {
        return "Unknown Bank";
    }
}

int main() {
    // نقشه پیش‌شماره‌های بانکی به نام بانک
    map<string, string> bankPrefixes = {
        {"603799", "Bank Melli Iran"},
        {"589210", "Bank Saderat Iran"},
        {"627648", "Bank Tosee Saderat Iran"},
        {"627961", "Bank Sanat o Madan"},
        {"603770", "Bank Keshavarzi Iran"},
        {"628023", "Bank Maskan"},
        {"627760", "Post Bank Iran"},
        {"502908", "Bank Tose'e Ta'avon"},
        {"627412", "Bank Eghtesad Novin"},
        {"622106", "Parsian Bank"},
        {"502229", "Bank Pasargad"},
        {"627488", "Bank Karafarin"},
        {"621986", "Bank Saman"},
        {"639346", "Bank Sina"},
        {"639607", "Bank Sarmayeh"},
        {"636214", "Bank Tat"},
        {"502806", "Shahr Bank"},
        {"502938", "Bank D"},
        {"603769", "Bank Saderat Iran"},
        {"610433", "Bank Mellat"},
        {"627353", "Bank Tejarat"},
        {"589463", "Refah Bank"},
        {"627381", "Ansar Bank"},
        {"639370", "Mehr Eghtesad Bank"}
    };

    string cardNumber;

    cout << "لطفاً شماره کارت 16 رقمی خود را وارد کنید: ";
    cin >> cardNumber;

    // بررسی طول شماره کارت
    if (cardNumber.length() != 16) {
        cout << "شماره کارت باید 16 رقمی باشد." << endl;
        return 1;
    }

    // بررسی اعتبار شماره کارت
    if (!isValidCardNumber(cardNumber)) {
        cout << "شماره کارت نامعتبر است." << endl;
        return 1;
    }

    // پیدا کردن بانک مربوطه
    string bankName = findBank(cardNumber, bankPrefixes);

    // چاپ اطلاعات کارت و بانک
    printFormattedCard(cardNumber);
    cout << "BANK: " << bankName << endl;

    return 0;
}
