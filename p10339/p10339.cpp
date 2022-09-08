#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cstdio>

int main()
{
	unsigned int k, m, segundos, horas, minutos;
	while (scanf("%u %u", &k, &m) != EOF)
	{

		segundos =  (43200 * (86400 - k) / abs((int)(k - m))) % 43200 + 30;
		horas = (segundos / 3600) % 12;
		minutos = (segundos % 3600) / 60;

		printf("%u %u %02u:%02u\n", k, m, horas == 0 ? 12 : horas, minutos);
	}
}
