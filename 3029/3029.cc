#include <iostream>

int main() {
    int sh, sm, ss, fh, fm, fs;
    
    scanf("%d:%d:%d", &sh, &sm, &ss);
    scanf("%d:%d:%d", &fh, &fm, &fs);
    
    fs -= ss;
    
    if (fs < 0) {
        fs += 60;
        --fm;
    }
    
    fm -= sm;
    
    if (fm < 0) {
        fm += 60;
        --fh;
    }
    
    fh -= sh;
    
    if (fh < 0 || fh == 0 && fm == 0 && fs == 0) {
		fh += 24;
	}
    
    printf("%02d:%02d:%02d", fh, fm, fs);
    return 0;
}