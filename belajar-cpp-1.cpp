#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

int main() {

    // 1. buat folder
    fs::create_directory("FolderA");
    cout << "FolderA dibuat.\n";

    // 2. buat file
    string filePath = "FolderA/test.txt";
    ofstream file(filePath);
    file.close();
    cout << "File test.txt dibuat.\n";

    // 4. line 1 hello line 2 word
    ofstream writeFile(filePath);
    writeFile << "hello\n";
    writeFile << "world\n";
    writeFile.close();
    cout << "File ditulis: hello dan world.\n";

    // 5. tambah tanda seru
    ifstream readFile(filePath);
    string content, line;
    while (getline(readFile, line)) {
        content += line + "!\n";
    }
    readFile.close();

    ofstream updateFile(filePath);
    updateFile << content;
    updateFile.close();
    cout << "File diupdate dengan tanda seru.\n";

    // 6. ganti semua enter jadi spasi
    ifstream readFile2(filePath);
    string newContent, word;
    while (readFile2 >> word) {
        newContent += word + " ";
    }
    readFile2.close();

    ofstream replaceFile(filePath);
    replaceFile << newContent;
    replaceFile.close();
    cout << "Enter diganti menjadi spasi.\n";

    // 7. copy file
    fs::copy(filePath, "FolderA/copy_test.txt", fs::copy_options::overwrite_existing);
    cout << "File berhasil dicopy.\n";

    // 8. move file
    fs::rename("FolderA/copy_test.txt", "FolderA/move_test.txt");
    cout << "File berhasil dipindahkan (rename).\n";

    // 9. oopy folder
    fs::copy("FolderA", "FolderB", 
             fs::copy_options::recursive | fs::copy_options::overwrite_existing);
    cout << "Folder berhasil dicopy ke FolderB.\n";

    return 0;
}
