//cout << "Number of data = ";
//cout << "Mean = ";
//cout << "Standard deviation = ";
#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
#include <fstream>

using namespace std;

int main() {
    int count = 0;          // นับจำนวนข้อมูล
    float sum = 0;          // ผลรวมของข้อมูล
    float sum_of_square = 0; // ผลรวมของค่ากำลังสอง
    string textline;

    ifstream source("score.txt");   // เปิดไฟล์ score.txt

    while (getline(source, textline)) {   // อ่านข้อมูลจากไฟล์ทีละบรรทัด
        float number = stof(textline);     // แปลงข้อมูลในแต่ละบรรทัดเป็นตัวเลข float
        sum += number;                     // คำนวณผลรวม
        sum_of_square += number * number;  // คำนวณผลรวมของค่ากำลังสอง
        count++;                           // นับจำนวนข้อมูล
    }

    float mean = sum / count;

    // คำนวณส่วนเบี่ยงเบนมาตรฐาน (Standard Deviation)
    float variance = (sum_of_square / count) - (mean * mean);
    float standard_deviation = sqrt(variance);

    // แสดงผลลัพธ์
    cout << "Number of data = " << count << "\n";
    cout << setprecision(3);
    cout << "Mean = " << mean << "\n";
    cout << "Standard deviation = " << standard_deviation << "\n";

    source.close();   // ปิดไฟล์

    return 0;
}