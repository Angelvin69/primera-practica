void graficar_figura(int id) {
    

    case TRAPECIO:
        int baseMayor = (int)(figura.dimension1 * escala);
        int baseMenor = (int)(figura.dimension2 * escala);
        int altura = (int)(figura.dimension3 * escala);

        
        float pendienteIzq = (float)(baseMayor - baseMenor) / (2 * altura);
        float pendienteDer = -pendienteIzq;

        
        for (int y = ALTO / 2 - altura; y <= ALTO / 2; y++) {
            
            int inicioX = ANCHO / 2 - (baseMayor - (y - (ALTO / 2 - altura)) * pendienteIzq) / 2;
            int finX = ANCHO / 2 + (baseMenor + (y - (ALTO / 2 - altura)) * pendienteDer) / 2;

            
            for (int x = inicioX; x <= finX; x++) {
                canvas[y][x] = '*';
            }
        }
        break;

    }
    void graficar_figura(int id) {

    case ELIPSE:
        int a = (int)(figura.dimension1 * escala); 
        int b = (int)(figura.dimension2 * escala); 

        for (int y = -b; y <= b; y++) {
            for (int x = -a; x <= a; x++) {
                if ((x * x) / (a * a) + (y * y) / (b * b) <= 1) {
                    canvas[ALTO / 2 + y][ANCHO / 2 + x] = '*';
                }
            }
        }
        break;
    }
}
