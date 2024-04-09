#include <stdio.h>
#include <malloc.h>
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
 
//��¼ͨ�������Թ������еĺᡢ������
struct Position {
    int x;
    int y;
};
 
//����ջ���е�ͨ����Ԫ��
struct SElement {
    int ord;//��¼����
    Position p;//��¼λ��
    int di;//��¼��һ�β�����һ·�����ٽ�·����λ��
};
 
struct MyStack {
    SElement* base;
    SElement* top;
    int stacksize;
};
 
//����һ��ջ��������ɹ��򷵻�1������ͷ���0
int InitStack(MyStack* s)
{
    s->base = (SElement*)malloc(STACK_INIT_SIZE * sizeof(SElement));//Ϊջ�����ʼ�ռ�
    if (!s->base) return 0;
    s->top = s->base;//�趨Ϊ��ջ
    s->stacksize = STACK_INIT_SIZE;
    return 1;
}
 
//�ж�ջ�Ƿ�Ϊ�գ�����ǿյľͷ���0������ͷ���1
int IsStackEmpty(MyStack* s)
{
    if (s->top == s->base) return true;
    return false;
}
 
//��ȡջ��Ԫ��,���ջΪ�վͷ���0 ����ͷ���1
int GetTop(MyStack* s, SElement* e)
{
    if (IsStackEmpty(s)) return 0;
    e = s->top - 1;
    return 1;
}
 
//��ȡջ�ĳ��ȣ�����ͨ�����򷵻�
int StackLength(MyStack* s)
{
    return s->top - s->base;
}
 
//����Ԫ��eΪ�µ�ջ��Ԫ�أ�����ɹ��򷵻�1�����򷵻�0
int  Push(MyStack* s, SElement e)
{
    if (s->top - s->base >= STACK_INIT_SIZE)
    {
        s->base = (SElement*)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElement));
        if (!s->base) return 0;
        s->top = s->base + s->stacksize;
        s->stacksize += STACKINCREMENT;
    }
    *(s->top) = e;
    s->top++;
    return 1;
}
 
//����ջ��Ԫ�ظ�ֵ��e�����ɹ�����1������ʧ�ܷ���0
int Pop(MyStack* s, SElement* e)
{
    if (IsStackEmpty(s)) return 0;
    *e = *(s->top - 1);
    s->top--;
    return 1;
}
 
//����ǽԪ��Ϊ1 ����·��Ϊ0 ��֪·��ΪcurStep ���ܹ�ͨ����·��Ϊ-2
#define m 15
#define n 18
int Maze[m][n] = {  { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
                    { 1,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,1 },
                    { 1,0,1,1,1,0,1,0,0,1,0,1,1,1,1,1,0,1 },
                    { 1,0,1,1,1,0,1,0,1,1,0,1,0,1,1,0,0,1 },
                    { 1,0,0,0,0,0,1,0,1,1,0,1,0,0,0,0,1,1 },
                    { 1,1,1,1,0,0,1,0,1,1,0,1,1,1,1,0,1,1 },
                    { 1,1,1,0,0,1,1,0,1,1,0,0,0,1,1,1,1,1 },
                    { 1,1,1,0,1,1,1,0,1,1,1,1,0,1,1,0,0,1 },
                    { 1,1,1,0,0,0,0,0,0,0,1,1,0,1,1,0,1,1 },
                    { 1,0,0,1,1,1,1,1,1,0,1,1,0,1,0,0,1,1 },
                    { 1,1,0,0,0,0,0,0,0,0,1,0,0,1,0,1,1,1 },
                    { 1,0,0,1,0,1,0,1,0,0,1,1,0,0,0,1,1,1 },
                    { 1,1,0,1,0,1,0,1,1,1,0,0,0,1,1,1,1,1 },
                    { 1,1,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1 },
                    { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 } };
 
//�����������쵱ǰ·���ܷ�ͨ��
bool Pass(Position posi)
{
    //ֻ��·������λ�õ�����Ϊ0���ǿ����ߵ�
    if (Maze[posi.x][posi.y] == 0)
    {
        return true;
    }
    return false;
}
 
//��˳ʱ�뷽����ҿ�ʼѰ�Ҿ�����ĳһ��λ�õ��ٽ�λ��
Position NextPosition(Position now, int direction)
{
    Position next;
    int x = now.x;
    int y = now.y;
    switch (direction)
    {
        //��
    case 1: {
        next.x = x;
        next.y = y + 1;
        break;
    }
            //��
    case 2: {
        next.x = x + 1;
        next.y = y;
        break;
    }
            //��
    case 3: {
        next.x = x;
        next.y = y - 1;
        break;
    }
            //��
    case 4:
    {
        next.x = x - 1;
        next.y = y;
        break;
    }
    default:break;
    }
    return next;
}
 
//�ı�ĵ�Ϊ������
void FootPrint(Position p, int step)
{
    Maze[p.x][p.y] = step;
}
 
//·�������ߵĻ�������-2�ı��
void MarkPrint(Position p)
{
    Maze[p.x][p.y] = -2;
}
 
//��ӡ���Թ�����
void Display_migong()
{
    for (int i = 0; i<m; i++)
    {
        for (int j = 0; j<n; j++)
        {
            if (Maze[i][j]<0)
                printf("%d ", Maze[i][j]);
            else if (Maze[i][j]<10)
                printf("%d  ", Maze[i][j]);
            else
                printf("%d ", Maze[i][j]);
        }
        printf("\n");
    }
}
 
int main()
{
 
    //�Թ���������
    MyStack  path;//��¼·����ջ
    InitStack(&path);//��ʼ��·������
    Position curp;//��ǰ����λ��
    Display_migong();
    //��ʼ����ǰλ��Ϊ�������
    curp.x = 1;
    curp.y = 1;
    int curStep = 1;//��̽���Ĳ���
    do
    {
        if (Pass(curp))
        {
            FootPrint(curp, curStep);//���߾����Թ����������㼣
//����һ��ջԪ�أ��洢����·�������ֵ�������Ԫ�ش洢��ջ����
            SElement e;
            e.di = 1;//��һ��·��Ϊ��һ��·����ұߵ�·��
            e.ord = curStep;
            e.p.x = curp.x;
            e.p.y = curp.y;
            Push(&path, e);//��·������ջ
if (curp.x == m - 2 && curp.y == n - 2) break; //�����ѹ���·���鵽���Թ����յ���˳�ѭ��
curp = NextPosition(curp, 1);//�ҵ�ǰһ�����Կ鶫���·������Ϊ���Կ�
            curStep++;//��̽���Ĳ�����һ
        }
        else//�����ǰ����·�����ܹ�ͨ���Ļ�
        {
            if (!IsStackEmpty(&path))
            {
                SElement e;
                Pop(&path, &e);
                curStep--;
                //�����е���Χ·�����Ѿ������Թ���·����ջ�����
                while (e.di == 4 && !IsStackEmpty(&path)) {
                    MarkPrint(e.p);
                    Pop(&path, &e);
                    curStep--;
                }
                //�����ǰջ������δ�����Ե�·���Ͳ���ʣ�����Χ·��
                if (e.di<4)
                {
                    curp = NextPosition(e.p, e.di + 1);
                    e.di++;
                    curStep++;
                    Push(&path, e);
                }
            }
        }
    } while (!IsStackEmpty(&path));
    printf("\n");
    //��ӡ������Թ�����
    Display_migong();
    return 0;
}

