#ifndef EJ1_H_
#define EJ1_H_

struct Viaje
{
    GrafoP<double>::vertice o,d;
    double coste;
};

Viaje ViajeMasCaro(const GrafoP<double> &G){
    matriz<GrafoP<double>::vertice> c;
    matriz<double> costes = FloydMayorCoste(G,c);
    Viaje viaje;
    viaje.o = viaje.d = viaje.coste = 0;

    for(GrafoP<double>::vertice v = 0; v < G.numVert(); ++v){
        for(GrafoP<double>::vertice w = 0; w < G.numVert(); ++w){
            if(costes[v][w] != GrafoP<double>::INFINITO && viaje.coste < costes[v][w]){
                viaje.o = v;
                viaje.d = w;
                viaje.coste = costes[v][w];
            }
        }
    }

    return viaje;
}


#endif