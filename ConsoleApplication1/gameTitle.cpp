#include <iostream>
#include <conio.h>   // _kbhit(), _getch() ���
#include <windows.h> // Sleep() ���

using namespace std;

const char* face[] = {
    "###############################",
    "###############################",
    "###############################",
    "###        #########        ###",
    "###        #########        ###",
    "###        #########        ###",
    "#############     #############",
    "#############     #############",
    "#########             #########",
    "#########             #########",
    "#########             #########",
    "#########    #####    #########",
    "#########    #####    #########",
    "###############################",
};

// Creeper ���� ����ϴ� �Լ�
void printFace(int offset) {
    for (int i = 0; i < 14; i++) { // 14���� ���� ���
        for (int j = 0; j < offset; j++) {
            cout << " "; // �¿�� �̵���Ű�� ���� ���� �߰�
        }
        cout << face[i] << endl; // Creeper ���� �� �� ���
    }
}

void clearScreen() {
    system("cls"); // ȭ���� ����� �Լ� (Windows ȯ�濡���� ��� ����)
}

int main() {
    int offset = 0;
    int direction = 1; // 1�̸� ���������� �̵�, -1�̸� �������� �̵�
    bool running = true;

    while (running) {
        if (_kbhit()) {  // Ű �Է��� �ִ��� Ȯ��
            char key = _getch();  // Ű �Է� �ޱ�
            if (key == 'q') {
                running = false;  // q �Է� �� ���� ����
            }
            else if (key == 's') {
                clearScreen();
                cout << "������ ����" << endl;  // s �Է� �� 3�� �� ���� ���
                Sleep(3000);
                clearScreen();
            }
        }

        clearScreen();
        printFace(offset);  // Creeper �� ���

        offset += direction; // �¿� �̵�
        if (offset == 10 || offset == 0) {  // ���� �������� ���� ��ȯ
            direction = -direction;
        }

        Sleep(100);  // �ִϸ��̼� �ӵ� ����
    }

    return 0;
}
