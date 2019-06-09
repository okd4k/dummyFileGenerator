// copyright 2019 okd4k
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:

// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.

// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.

// File name: fileGerneator.cc
// Author: okd4k
// This is the code for dummyFileGenerator
//

#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

#define LICENSE_MIT     1
#define MIT_FILE_NAME   "MIT.txt"
#define RESOURCE_LOCATION   ""



int main()
{
    string fileAuthor;
    cout << "File Author: ";
    cin >> fileAuthor;


    string fileName;
    cout << "File Name: ";
    cin >> fileName;

    string fileExtension;
    cout << "File Extension: ";
    cin >> fileExtension;


    string tempInput;
    bool ifCreateHeader;
    while (1) {
        cout << "if create a header file? Y or N: ";
        cin >> tempInput;
        if (!tempInput.size()) {
            continue;
        }
        else {
            if (tempInput[0] == 'Y' || tempInput[0] == 'y') {
                ifCreateHeader = true;
                break;
            }
            else if (tempInput[0] == 'N' || tempInput[0] == 'n') {
                ifCreateHeader = false;
                break;
            }
            else {
                cout << "You are naughty, that was an invalid input." << endl;
            }
        }
    }

    string fileLicense;
    string fileLicenseLocaltion;
    cout << "File License: ";
    cin >> fileLicense;

    if (fileLicense == "MIT" || fileLicense == "mit") {
        fileLicenseLocaltion.assign(RESOURCE_LOCATION);
        fileLicenseLocaltion.append(MIT_FILE_NAME);
    }
    else {
        cout << "License " << fileLicense << " is not supported yet." \
        << endl;
    }

    std::ofstream targetFileStream;
    targetFileStream.open(fileName + "." + fileExtension);

    if (fileExtension == "cc" || fileExtension == "cpp") {
        // todo: should be able to know which year it is itself
        // todo: this part should be a function
        targetFileStream << "// copyright 2019 " << fileAuthor << endl << endl;
        std::ifstream licenseStream(fileLicenseLocaltion);
        if (licenseStream.is_open()) {
            string line;
            while (getline(licenseStream, line)) {
                if (line.size()) {
                    targetFileStream << "// " << line << endl;
                }
                else {
                    targetFileStream << endl;
                }
            }
            licenseStream.close();
        }
        else {
            cout << "License file not right." << endl;
        }
        targetFileStream << endl << "//" << endl;
        targetFileStream << "// File name: " << fileName << "." << fileExtension
        <<endl;
        targetFileStream << "// Author: " << fileAuthor << endl;
        targetFileStream << "//" << endl;
        targetFileStream.close();

        if (ifCreateHeader) {
            std::ofstream targetFileStream;
            targetFileStream.open(fileName + ".h");

            targetFileStream << "// copyright 2019 " << fileAuthor << endl << endl;
            std::ifstream licenseStream(fileLicenseLocaltion);
            if (licenseStream.is_open()) {
                string line;
                while (getline(licenseStream, line)) {
                    if (line.size()) {
                        targetFileStream << "// " << line << endl;
                    }
                    else {
                        targetFileStream << endl;
                    }
                }
                licenseStream.close();
            }
            else {
                cout << "License file not right." << endl;
            }
            targetFileStream << endl << "//" << endl;
            targetFileStream << "// File name: " << fileName << ".h" <<endl;
            targetFileStream << "// Author: " << fileAuthor << endl;
            targetFileStream << "//" << endl;
            targetFileStream.close();

        }

    }
    else {
        cout << "file format " << fileExtension << " is not supported yet." \
        << endl;
    }









    return 0;
}
