//2017.02.05
//1 일 1 알고리즘 프로젝트(Selection sort)
//By.Kim00425

#include<iostream>
#include<vector>
#include<random>

auto Time=std::chrono::system_clock::now(); // system의 time을 이용
auto duration =Time.time_since_epoch();
auto mil=std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();

std::mt19937 Rng((uint32_t)mil);    //불확실한 난수생성을 위한 생성기 자세한 사항은 cplusplus.com 참조

void ShowNumbers(std::vector<int> num,int max); //생성 및 수정된 집합 출력
void Selectionsort(std::vector<int> &num,int max); //선택 정렬

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
    
    Selectionsort(Numbers, MAX);
    std::cout<<std::endl<<"After Numbers:";
    ShowNumbers(Numbers,MAX);
}
void Selectionsort(std::vector<int> &num,int max)
{
    
    int temp;
    int* Min = nullptr;             //Minimum 숫자를 저장 할 영역을 주소값으로 참조함 or vector의 vector.at으로도 가능
    for(int i=0;i<num.size();i++)
    {
        Min=&num[i];
        for(int j=i+1;j<num.size();j++)
        {
            if(*Min>num[j])
            {
                Min=&num[j];
            }
        }
        if(*Min!=num[i])
        {
            temp=num[i];
            num[i]=*Min;
            *Min=temp;
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
