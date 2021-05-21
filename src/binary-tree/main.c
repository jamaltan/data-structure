#include <stdio.h>
#include <assert.h>
#include <time.h>
#include "tree.h"

int main(int argc, char **argv) {
        PBT root, left, right, lleft, lright, rleft, rright;
        int s, h;
        int len = 10;
        int i;
        PBT t1, t2;
        time_t start_t, end_t;
        double diff_t;

        root = create(27);

        left = create(14);
        right = create(35);

        lleft = create(10);
        lright = create(19);

        rleft = create(31);
        rright = create(42);

        root->left = left;
        root->right = right;

        root->left->left = lleft;
        root->left->right = lright;

        root->right->left = rleft;
        root->right->right = rright;

        //	if(argc == 2 && argv[1]) len = atoi(argv[1]);
        //	for(i = 1; i <= len; i++){
        //		add(root, i);
        //	}
        //	add(root, 10);

        s = size(root);
        printf("root size: %d\n", s);
        h = height(root);
        printf("root height: %d\n", h);

        preorder(root);
        printf("\n");

        inorder(root);
        printf("\n");

        postorder(root);
        printf("\n");

        time(&start_t);
        t1 = search(root, 10);
        time(&end_t);
        diff_t = difftime(end_t, start_t);
        printf("target address: %p, search time: %f\n", t1, diff_t);

        time(&start_t);
        t2 = search(root, 10);
        time(&end_t);
        diff_t = difftime(end_t, start_t);
        printf("target address: %p, search time: %f\n", t2, diff_t);

        return 0;
}
