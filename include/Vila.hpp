class Vila
{
public:
    Vila();
    Vila(int id, int maxVizinhos);
    ~Vila();
    int getId();
    int getNumeroVizinhas();
    Vila** getVilasVizinhas();
    void setVilaVizinha(Vila* vila);

private:
    int id;
    int numeroVizinhas;
    Vila** vilasVizinhas; 
};