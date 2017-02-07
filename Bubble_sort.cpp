//2017.01.29
//1 일 1 알고리즘 프로젝트(Bubble sort)
//By.Kim00425

#include<iostream>
#include<vector>
#include<random>

auto Time=std::chrono::system_clock::now(); // system의 time을 이용
auto duration =Time.time_since_epoch();
auto mil=std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

std::mt19937 Rng((uint32_t)mil);    //불확실한 난수생성을 위한 생성기 자세한 사항은 cplusplus.com 참조

void ShowNumbers(std::vector<int> num,int max); //생성 및 수정된 집합 출력
void Bubblesort(std::vector<int> &num,int max);  //버블 정렬

int main(void)
{
    std::vector<int> Numbers;
    int MAX;
    
    std::cout<<"How long Number Length?\nInput:";
    std::cin>>MAX;
    for(int i=0;i<MAX;i++)
    {
        Numbers.push_back(Rng()%MAX+1); //난수생성기로 집합 생성
    }
    std::cout<<"Before Numbers:";
    ShowNumbers(Numbers,MAX);
    Bubblesort(Numbers, MAX);   //버블 정렬 시작
    
    std::cout<<std::endl<<"After Numbers:";
    ShowNumbers(Numbers,MAX);
}
void Bubblesort(std::vector<int> &num,int max)
{
    int temp;
    for(int i=1;i<max;i++)
    {
        for(int j=0;j<max-i;j++)
        {
            if(num[j]>num[j+1])
            {
                temp=num[j];
                num[j]=num[j+1];
                num[j+1]=temp;
            }
        }
    }
}
void ShowNumbers(std::vector<int> num,int max)
{
    std::cout<<num[0]<<",";
    for(int i=1;i<max-1;i++)
    {
        
        std::cout<<num[i]<<",";
    }
    std::cout<<num[max-1];
    std::cout<<std::endl;
}
