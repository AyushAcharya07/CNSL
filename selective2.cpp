#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

using namespace std;

class ARQ {
public:
    int n, size;
    vector<int> frames;
    vector<bool> acknowledged;

    void input() {
        cout << "Enter the number of frames: ";
        cin >> n;

        cout << "Enter the frames: ";
        for (int i = 0; i < n; i++) 
        {
            int frame;
            cin >> frame;
            frames.push_back(frame);
            acknowledged.push_back(false);
        }

        cout << "Enter the window size: ";
        cin >> size;
    }

    void sendFrame(int frame) 
    {
        cout << "Sending Frame No. " << frame << endl;
    }

    void acknowledgeFrame(int frame) 
    {
        cout << "Acknowledgment for Frame No. " << frame << endl;
    }

    void timeoutFrame(int frame) 
    {
        cout << "Timeout reached for Frame No. " << frame << "!! Retransmitting the Frame" << endl;
        //sendFrame(frame); // Retransmit the frame
    }

    void compute() 
    {
        int i = 0;
        //srand(time(NULL));

        while (i < n) 
        {
            int j;
            for (j = i; j < i + size && j < n; j++) {
                sendFrame(frames[j]);
            }

            for (int k = i; k < j; k++) {
                int flag = rand() % 2;
                if (flag == 0) {
                    acknowledgeFrame(frames[k]);
                    acknowledged[k] = true;
                }
                else
                {
                    timeoutFrame(frames[k]);
                    sendFrame(frames[k]);
                    acknowledgeFrame(frames[k]);
                }
            }
           

            i = j; 
        }
    }
};

int main() {
    ARQ a;
    a.input();
    a.compute();
    return 0;
}
