struct Component {
	int pid;
	int q;
	int t;
};

struct DataPoint {
	int n; //number of pids
	struct Component components[100];
};
