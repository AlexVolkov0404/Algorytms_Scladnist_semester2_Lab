#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>	// getch
#include <ctype.h>
#include "graphics.h"
#pragma comment(lib,"graphics.lib")
using namespace std;
typedef struct BTN {
    int dat;

    BTN* lt, * rt;
} BINTRN, * BINTRP;
BINTRP nwnode(int v, BINTRP pl, BINTRP pr) {
    BINTRP p = new BINTRN;
    p->dat = v; p->lt = pl; p->rt = pr;
    return p;
}
void print_tree1(BINTRP r, int x1, int x2, int y0) {
    int x0, wrkx1, wrkx2, wrky;
    char buf[20];
    int oldcolor;
    int dy;
    dy = 50;
    if (!r) return;

    x0 = (x1 + x2) / 2;
    wrky = y0 + dy;

    if (r->lt != NULL) {
        wrkx1 = x1;
        wrkx2 = x0;
        line(x0, y0, (wrkx1 + wrkx2) / 2, wrky);
        print_tree1(r->lt, wrkx1, wrkx2, wrky);
    }
    if (r->rt != NULL) {
        wrkx1 = x0;
        wrkx2 = x2;
        line(x0, y0, (wrkx1 + wrkx2) / 2, wrky);
        print_tree1(r->rt, wrkx1, wrkx2, wrky);
    }
    //narisovat' uzel
    oldcolor = getcolor();
    setcolor(6);
    circle(x0, y0, 10);
    setcolor(oldcolor);


    sprintf(buf, "%d", r->dat);
    settextjustify(CENTER_TEXT, CENTER_TEXT);
    outtextxy(x0, y0, buf);

}
double number(char s[256]) {
    double n;
    double m;
    n = strlen(s);
    m = 0;
    int q = 1;
    for (int i = n - 1; i >= 0; i--) {
        m = m + ((int)s[i] - '0') * q;
        q = q * 10;
    }
    return m;
}
BINTRP zapov(vector<int> keys) {
    BINTRP tree, parent, node, tr;
    int m;
    char nx[256];
    char nt[256];
    ifstream file1, file2;
    file1.open("text1.txt");
    file2.open("text2.txt");
    file1 >> nx;
    //m = number(nx);

    int o = 0;

    tr = nwnode(keys[0], NULL, NULL);
    int h = 1;
    while (h<keys.size()) {

       
        file1 >> nx;
        m = keys[h];

        tree = tr;
        for (parent = tree; tree != NULL; ) {
            parent = tree;
            if (m < tree->dat)
                tree = tree->lt;
            else if (m > tree->dat)
                tree = tree->rt;
            else
                return 0;
        }
        node = nwnode(m, NULL, NULL);
        if (m < parent->dat)
            parent->lt = node;
        else
            parent->rt = node;
        h++;
    }
    int gdriver = DETECT, gmode, errorcode;
    char c[256] = " ";
    //initgraph(&gdriver, &gmode, c);
    //// read result of initialization
    //errorcode = graphresult();
    /*print_tree2(tr, 1, getmaxx(), 40);*/
    file1.close();
    file2.close();
    /* getch();
     closegraph();*/
     /* }*/
    return tr;
}
BINTRP exchange(BINTRP t) {
    if (t->lt == NULL && t->rt == NULL)
        ;
    else     // Может быть три случая, ни один не пустой, левый пустой, правый пустой
    {
        // поменять местами левые и правые поддеревья
        BINTRP temp = t->lt;
        t->lt = t->rt;
        t->rt = temp;
    }
    // Если левое поддерево этого узла после обмена не пусто, продолжаем искать узел, который можно обменять
    if (t->lt)
        exchange(t->lt);
    if (t->rt)
        exchange(t->rt);
    return t;
}
int poshuk(BINTRP tr) {
    int hlt = 0;
    int hrt = 0;
    int h = 0;
    BINTRP tree, parent, node;
    tree = tr;
    if (tree != NULL) {
        hlt = poshuk(tree->lt);
        hrt = poshuk(tree->rt);
        if (hlt >= hrt) h = hlt + 1;
        else h = hrt + 1;
    }

    return h;
}