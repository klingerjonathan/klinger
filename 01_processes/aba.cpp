#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>
#include <csignal>
#include <sys/wait.h>
#include <unistd.h>

using namespace std;

int main(){
    int pid1 = fork();
    int pid2 = fork();
    int status;

    //Parent
    if(pid1 > 0 && pid2 > 0){
        cout << endl << "Sleeping for 3 seconds" << endl << flush;
        sleep(3);

        cout << "\nkilling both subprocesses with pids "  
             << pid1 << " and " << pid2 << endl;  


        kill(pid1, 9);
        kill(pid2, 9);

        cout << "wating for both subprocesses to be dead" << endl;
        
        waitpid(pid1, &status, 0);
        cout << "subprocess " << pid1 << " exited with " 
             << WEXITSTATUS(status) << endl;  

        waitpid(pid2, &status, 0);
        cout << "subprocess " << getpid() << " exited with " 
             << WEXITSTATUS(status) << endl;  
    } 
    else if(pid1 == 0 && pid2 > 0){
            int run1 = execl("./charout", "B", nullptr);
            if (run1 == -1){
                cout << "starting charout failed: no such file or direcory" << flush;
            } else{
                cout << run1 << flush;
            }
    } 
    else if(pid1 > 0 && pid2 == 0){
            int run2 = execl("./charout", "A", nullptr);
            if (run2 == -1){
                cout << "starting charout failed: no such file or direcory" << flush;
            } else{
                cout << run2 << flush;
            }
    }
}

