#define _CRT_SECURE_NO_DEPRECATE
#include <cmath>
#include <cstdio>

typedef long long ll;

int main()
{
	ll k, m, segundos, horas, minutos;
	while (scanf("%lld %lld", &k, &m) != EOF)
	{
		// Calculando a hora em segundos.
		// D = 86400, D/2 = 43200
		// + 30 segundos para arredondar ao minuto mais próximo.
		segundos =  (43200 * (86400 - k) / abs(k - m)) % 43200 + 30;

		horas = (segundos / 3600) % 12;
		minutos = (segundos % 3600) / 60;

		printf("%lld %lld %02lld:%02lld\n", k, m, horas == 0 ? 12 : horas, minutos);
	}
}
