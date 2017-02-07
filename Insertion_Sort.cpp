//2017.02.07.
//1 일 1 알고리즘 프로젝트(Insertion sort)
//By.Kim00425

#include<iostream>
#include<vector>
#include<random>

auto Time=std::chrono::system_clock::now(); // system의 time을 이용
auto duration =Time.time_since_epoch();
auto mil=std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

std::mt19937 Rng((uint32_t)mil);    //불확실한 난수생성을 위한 생성기 자세한 사항은 cplusplus.com 참조

void ShowNumbers(std::vector<int> num,int max); //생성 및 수정된 집합 출력
void Insertionsort(std::vector<int> &num,int max);  //삽입 정렬

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
    Insertionsort(Numbers, MAX);   //삽입 정렬 시작
    
    std::cout<<std::endl<<"After Numbers:";
    ShowNumbers(Numbers,MAX);
}
void Insertionsort(std::vector<int> &num,int max)
{
    
    for(int i=1;i<max;i++)
    {
        for(int j=i;j!=0;j--)
        {
            if(num[j-1]<=num[j])
            {
                break;
            }
            std::iter_swap(&num[j], &num[j-1]);      //STL의 iter 문법사용.(Call by reference)
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
