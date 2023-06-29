#include "HeaderLed.h"
int main(void)
{
	init();
	Inicializar_KIT();
	while (1)
	{
		mde_intercambiar_frecuencias();
		mde_parpadeo();
	}
	return 0;
}