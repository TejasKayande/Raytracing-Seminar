
#include <windows.h>

int main(void) {

    const LPCSTR OUTPUT_FILE = "images/first.ppm";
    HANDLE file_handle = nullptr;

    file_handle = CreateFile(OUTPUT_FILE, GENERIC_WRITE, 0, NULL,
                             CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

    if (file_handle == nullptr) return -1;

    const char* data1 = "Hello World";

    const char* data2 =
"P3 \
4 4 \
15 \
 0  0  0    0  0  0    0  0  0   15  0 15 \
 0  0  0    0 15  7    0  0  0    0  0  0 \
 0  0  0    0  0  0    0 15  7    0  0  0 \
15  0 15    0  0  0    0  0  0    0  0  0";

    DWORD bytes_written;
    BOOL success = WriteFile(file_handle, data1, strlen(data), &bytes_written, NULL);

    if (!success) return -1;
    return 0;
}
