#include<iostream>
#include<random>
#include<unistd.h>
#include<starpu.h>

void rand_time_cpu(void*buffers[], void *cl_arg)
{
    float sum = 0.0;
    int N; 
    float from, to;
    starpu_codelet_unpack_args(cl_arg, &N, &from, &to);
	std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float>dis(from, to);
    for (int i = 0; i < N; i++)
    {
        std::cout << dis(gen) <<"\n";
        sleep(dis(gen));
        sum = sum + dis(gen);
    }
    std::cout <<"ans:"<< sum << "\n";
}

struct starpu_codelet rand_time_cl = {
    .cpu_funcs = { rand_time_cpu }
};

int main()
{
	int ret = starpu_init(NULL);
	STARPU_CHECK_RETURN_VALUE(ret, "starpu_init");
    int N = 100;
    float from = 0.1, to = 0.3;
    starpu_task_insert(&rand_time_cl, STARPU_VALUE, &N,    sizeof(N), 
                                      STARPU_VALUE, &from, sizeof(from), 
                                      STARPU_VALUE, &to,   sizeof(to),  0);
	starpu_task_wait_for_all(); 
	starpu_shutdown();
	return 0;
}