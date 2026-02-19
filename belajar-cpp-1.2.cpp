#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace fs = std::filesystem;
using namespace std;

int main() {

    string folderA = "FolderA";
    string folderB = "FolderB";
    string filePath = folderA + "/test.txt";

    int pilihan;

    do {
        cout << "\n===== pilih salah satu =====\n";
        cout << "1. Buat FolderA\n";
        cout << "2. Buat & Tulis File (hello, world)\n";
        cout << "3. Update File (tambah !)\n";
        cout << "4. Ganti Enter jadi Spasi\n";
        cout << "5. Copy File\n";
        cout << "6. Move File\n";
        cout << "7. Copy Folder ke FolderB\n";
        cout << "8. Hapus File\n";
        cout << "9. Hapus Folder\n";
        cout << "10. Keluar\n";
        cout << "Pilih (1-10): ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                fs::create_directory(folderA);
                cout << "FolderA dibuat.\n";
                break;

            case 2: {
                ofstream file(filePath);
                file << "hello\n";
                file << "world\n";
                file.close();
                cout << "File ditulis.\n";
                break;
            }

            case 3: {
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
                break;
            }

            case 4: {
                ifstream readFile(filePath);
                string newContent, word;
                while (readFile >> word) {
                    newContent += word + " ";
                }
                readFile.close();

                ofstream replaceFile(filePath);
                replaceFile << newContent;
                replaceFile.close();
                cout << "Enter diganti menjadi spasi.\n";
                break;
            }

            case 5:
                fs::copy(filePath,
                         folderA + "/copy_test.txt",
                         fs::copy_options::overwrite_existing);
                cout << "File berhasil dicopy.\n";
                break;

            case 6:
                fs::rename(folderA + "/copy_test.txt",
                           folderA + "/move_test.txt");
                cout << "File berhasil dipindahkan.\n";
                break;

            case 7:
                fs::copy(folderA, folderB,
                         fs::copy_options::recursive |
                         fs::copy_options::overwrite_existing);
                cout << "Folder berhasil dicopy ke FolderB.\n";
                break;

            case 8:
                fs::remove(filePath); 
                cout << "File test.txt dihapus.\n";
                break;

            case 9:
                fs::remove_all(folderA);
                cout << "FolderA dihapus.\n";
                break;


            case 10:
                cout << "Keluar program.\n";
                break;

            default:
                cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 10);

    return 0;
}
