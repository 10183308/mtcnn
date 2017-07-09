#include "network.h"
#include "mtcnn.h"
#include <time.h>
#pragma comment(lib, "libopenblas.dll.a")

int main()
{
	//��Ϊִ��Ŀ¼�����õ�openblas/x64���ˣ���֤dll���������룬��ʱ��ͼƬ·�������Ҫ����ȥ2��
	Mat im = imread("../../00284.jpg");
	mtcnn find(im.cols, im.rows);
	vector<Rect> objs = find.detectObject(im);
	for (int i = 0; i < objs.size(); ++i)
		rectangle(im, objs[i], Scalar(0, 255), 2);

	imshow("demo", im);
	waitKey();
    return 0;
}