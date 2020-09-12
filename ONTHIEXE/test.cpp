#include "graphics.h"
    #include "stdio.h"
    main()
    {
    int mh=0, mode;
    initgraph(&mh,&mode,"C:\\TC\\BGI");
    printf("\n Gia tri so cua man hinh la : %d",mh);
    printf("\n Gia tri so mode do hoa la : %d",mode);
    closegraph();
    }
