bool TopologicalSort(Graph G){
    InitStack(S);
    int i;
    for(i=0;i<G.vexnum;i++){
        if(indegree[i]==0)
        Push(S,i);
    }
    int count=0;

    while(!IsEmpty(S)){
        Pop(S);
        print[count++]=i;//输出顶点i
        for(p=G.vertices[i].firstarc;p;p=p->nextarc){
            //将所有i指向的顶点入度减一，并且将入读减为0的顶点压入栈S
            v = p->adjvex;
            if(!(--indegree[v]))
                Push(S,v);
        }
    }
    if(count<G.vexnum)//计数，当少于总顶点数时，非
        return false;
    else
        return true;
}