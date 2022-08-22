 // make by liupengbin
 // date is (2022年8月22日)

#include <stdio.h>
#include <stdlib.h>

typedef struct google_text
{
    int a;
    int b;
    int output;
    int (* TestEMFunc)(int, int);/* data */
}T_EMTest;

T_EMTest * addFunc( int(* TestEMFunc)(int, int), int a, int b, int output ){
    T_EMTest * m_EMTest = (T_EMTest *)malloc(sizeof(T_EMTest)); // 为结构体动态申请内存
    m_EMTest->a = a;
    m_EMTest->b = b;
    m_EMTest->output = output;
    m_EMTest->TestEMFunc = TestEMFunc;
    return m_EMTest;  
} // 使用函数指针来初始化结构体 good。将要检测的函数和其参数，及想要的目标结构一同传入初始化

void runEMTest(T_EMTest * p_EMTest){  // 传入结构体为你想要的结果 output
    if(p_EMTest != NULL){
        int goal = p_EMTest->TestEMFunc(p_EMTest->a, p_EMTest->b); // 为函数运算得出的结果
        if(goal == p_EMTest->output){ // p_EMTest->output 是你输入的想要的结果
            printf("ok\n");
        }else{
            printf("no test goal %d != actical %d\n",goal, p_EMTest->output);
        }
        free(p_EMTest); // 地址传递可以在这里释放，虽然换了一个变量名
        // 如果前面创建了很多个addFunc函数（其中malloc很多内存空间）
        // 但后面没有runEMTest（也就没有free）感觉可能会内存泄漏
    }
}

int add(int a, int b){
    return a + b;
}

int main (){
    int c = 0, d= 4;
    T_EMTest * testadd = addFunc(add,c,d,6);
    runEMTest(testadd);
    return 0;
}
