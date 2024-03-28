#include <bits/stdc++.h>
using namespace std;
void fastIO() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
}

string removeSpaces(string str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end()); // loại bỏ các space
    str.erase(remove(str.begin(), str.end(), '\t'), str.end()); // Loại bỏ cả tab
    return str;
}

string binaryToHex(string binaryStr) {
    // Kiểm tra xem chuỗi nhị phân có chứa số khác 0 không
    bool allZeroes = true;
    for (char bit : binaryStr) {
        if (bit != '0') {
            allZeroes = false;
            break;
        }
    }
    if (allZeroes) {
        return "0";
    }


    bitset<32> bits(binaryStr); // Chuyển chuỗi nhị phân thành bitset
    int decimalNum = bits.to_ulong(); // Chuyển từ bitset sang số nguyên
    string hexStr = "";

    // Bảng chữ cái thập lục phân
    char hexChars[] = "0123456789abcdef";

    while (decimalNum > 0) {
        int remainder = decimalNum % 16;
        hexStr = hexChars[remainder] + hexStr;
        decimalNum /= 16;
    }

    return hexStr;
}
vector<string> splitString(const string &str, int chunkSize) {
    vector<string> chunks;
    for (size_t i = 0; i < str.size(); i += chunkSize) {
        chunks.push_back(str.substr(i, chunkSize));
    }
    return chunks;
}

int chunkSize = 4;
// VD matrix của chữ H trong input
int main() {
    fastIO();
    vector<string>res; // vector lưu trữ rasters[];
    string row;

    while (getline(cin, row)) { // đọc từng dòng dữ liệu
        row = removeSpaces(row);// xoá bỏ khoảng trắng
        vector<string>chunks = splitString(row, 4); // cắt thành 4 khối
    
        cout << "0x" << binaryToHex(chunks[0]) << binaryToHex(chunks[1]) << " - ";
        cout << "0x" << binaryToHex(chunks[2]) << binaryToHex(chunks[3]);
    
        res.push_back("0x" + binaryToHex(chunks[2]) + binaryToHex(chunks[3]));
        res.push_back("0x" + binaryToHex(chunks[0]) + binaryToHex(chunks[1]));
        cout << endl;
    }

    int xuongdong = 0;
    cout << "\nrasters[] = {\n\t";
    for (int i = res.size() - 1; i >= 0; i--) {
        cout << res[i] << ", ";
        xuongdong++;
        if (xuongdong % 8 == 0) cout << "\n\t";
    }
    cout << "}";
}