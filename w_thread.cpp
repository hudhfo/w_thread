#include <stdio.h>
#include <windows.h>
#include <mutex>//互斥锁

//CRITICAL_SECTION cs;//定义临界区全局变量
std::mutex m_ProcessMutex; //定义互斥锁
const unsigned int THREAD_NUM = 50;
unsigned int g_Count = 0;

DWORD WINAPI Thread(LPVOID lpParam)
{
    Sleep(50);
    // m_ProcessMutex.lock();
    EnterCriticalSection(&cs);
    g_Count++;
    LeaveCriticalSection(&cs);
    // m_ProcessMutex.unlock();
    Sleep(50);
    return 0;
}
int main()
{

    HANDLE hThread[THREAD_NUM];
    //初始化临界区
    InitializeCriticalSection(&cs);
    for (int i = 0;i < THREAD_NUM;i++)
    {
        //创建线程
        hThread[i] = CreateThread(NULL, 0, Thread, &i, 0, NULL);
    }
    //等待所有进程结束
    WaitForMultipleObjects(THREAD_NUM, hThread, TRUE, INFINITE);
    printf("%d", g_Count);
    //删除临界区
    DeleteCriticalSection(&cs);
    return 0;
}
