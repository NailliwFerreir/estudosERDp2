#include<stdio.h>
#include<stdlib.h>
#define max 3

struct no
{
    int info;
    struct no *prox;
};
typedef struct no No;
typedef struct no Lista;

typedef struct pilha
{
    No *Topo;
}Pilha;

typedef struct fila
{
    No *ini;
    No *fim;
}Fila;

//Pilha
Pilha* CriaPilha (void)
{
     Pilha *p;
     p=(Pilha*)malloc(sizeof(Pilha));
     p->Topo = NULL;
   return p;
};

No* ins_ini (No* t, int a)
{
    No* aux = (No*) malloc(sizeof(No));
    aux->info = a;
    aux->prox = t;
    return aux;
};

void push (Pilha* p, int v)
{
    p->Topo = ins_ini(p->Topo,v);
};

No* ret_ini (No* l)
{
    No* p = l->prox;
    free(l);
    return p;
};

int pop (Pilha* p)
{
    int v;
    if (p==NULL)
    {
        printf("Pilha vazia.\n");
        exit(1); /* aborta programa */
    }
    v = p->Topo->info;
    p->Topo = ret_ini(p->Topo);
    return v;
};

Pilha * liberaPilha (Pilha* p)
{
    No* q = p->Topo;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(p);
    return(NULL);
};

void imprimePilha (Pilha* p)
{
    No* q;
    if(!p)
    {
        printf("\n\n\tPILHA VAZIA!!!!");
    }
    else
    {
        printf("\n\n\tPILHA: ");
        for (q=p->Topo; q!=NULL; q=q->prox)
        {
            printf("\n%d",q->info);
        }
    }
};

int vaziaPilha(Pilha *p)
{
    if (!p->Topo)
    {
        return 1; //pilha vazia
    }
    return 0;
}


//Fila

int VaziaFila (Fila* f)
{
    if (f->ini==NULL) return 1;
    return 0;
}

Fila* CriaFila ()
{
    Fila* f = (Fila*) malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

No* ins_fim (No* fim, int A)
{
    No* p = (No*) malloc(sizeof(No));
    p->info = A;
    p->prox = NULL;
    if (fim != NULL) /* verifica se lista n�o estava vazia */
    fim->prox = p;
    return p;
}

void InsereFila (Fila* f, int v)
{
    f->fim = ins_fim(f->fim,v);
    if (f->ini==NULL) /* fila antes vazia? */
    f->ini = f->fim;
}

No* retira_ini (No* ini)
{
    No* p = ini->prox;
    free(ini);
    return p;
}

int RetiraFila (Fila* f)
{
    int v;
    if (VaziaFila(f))
    {
        printf("Fila vazia.\n");
        exit(0); /* aborta programa */
    }
    v = f->ini->info;
    f->ini = retira_ini(f->ini);
    if (f->ini == NULL) /* fila ficou vazia? */
    f->fim = NULL;
    return v;
}

void imprimeFila (Fila* f)
{
    No* q;
    printf("\n");
    printf("Inicio->");
    for (q=f->ini; q!=NULL; q=q->prox)
    {
     printf("%d - ",q->info);   
    }
    printf("<-Fim");
}

Fila* liberaFila (Fila* f)
{
    No* q = f->ini;
    while (q!=NULL)
    {
        No* t = q->prox;
        free(q);
        q = t;
    }
    free(f);
    return NULL;
}

//Lista de estudos códigos

Pilha *ex6_A(Fila *f)//Retira da Fila e coloca na Pilha
{
    int aux=0;
    Pilha *p=CriaPilha();
    while(VaziaFila(f)!=1)
    {
        aux=RetiraFila(f);
        push(p,aux);
    }
    return p;
}
Fila *ex6_B(Pilha *p)//Pilha -> Fila topo da Pilha é o inicio da Fila
{
    int aux=0;
    Fila *f=CriaFila();
    while(vaziaPilha(p)!=1)
    {
        aux=pop(p);
        InsereFila(f,aux);
    }
    return f;
}
Fila *ex6_C(Pilha *p)//O topo da Pilha é o final da Fila
{
    int aux=0;
    Pilha *p2=CriaPilha();//passo para essa dps para a fila e ai fica invertido
    Fila *f=CriaFila();
    while(vaziaPilha(p)!=1)
    {
        aux=pop(p);
        push(p2,aux);
    }
    aux=0;
    while(vaziaPilha(p2)!=1)
    {
        aux=pop(p2);
        InsereFila(f,aux);
    }
    return f;
}
Fila *ex6_D(Fila *f,Fila *f2)//Mescla duas filas sem repetir numeros
{
    No *q;
    int num=0,flag=0;
    Fila *f3=CriaFila();
    while(VaziaFila(f)!=1)
    {
        num=RetiraFila(f);
        InsereFila(f3,num);
    }
    while(VaziaFila(f2)!=1)
    {
        num=RetiraFila(f2);
        flag=0;
        for (q=f3->ini; q!=NULL; q=q->prox)
        {
            if(q->info==num)
            {
                flag=1;
            }
        }
        if(flag==0)
        {
            InsereFila(f3,num);
        }
    }
    return f3;
}

int main ()
{
    system("cls");
    Pilha *P =CriaPilha();
    Fila *F = CriaFila();
    Fila *F2=CriaFila();
    Fila *F3=CriaFila();
    //dados para testar
   /* 
    push(P,13);
    push(P,10);
    push(P,12);
    push(P,54);
    push(P,33);
    push(P,22);
    push(P,15);
    */

    InsereFila(F,10);
    InsereFila(F,12);
    InsereFila(F,54);
    InsereFila(F,33);
    InsereFila(F,22);

    InsereFila(F2,14);
    InsereFila(F2,32);
    InsereFila(F2,54);
    InsereFila(F2,33);
    InsereFila(F2,24);

    //P=ex6_A(F);
    //F=ex6_B(P);
    //F=ex6_C(P);
    //F3=ex6_D(F,F2);

    printf("\n \nImprimindo a Fila 1...\n");
    imprimeFila(F);

    printf("\n \nImprimindo a Fila 2...\n");
    imprimeFila(F2);
   
    printf("\n \nImprimindo a Fila 3...\n");
    F3=ex6_D(F,F2);
    imprimeFila(F3);

    //("\n \nImprimindo a Pilha...\n \n ");
    //imprimePilha(P);
    
    liberaFila(F);
    liberaPilha(P);
    return 0;
}
