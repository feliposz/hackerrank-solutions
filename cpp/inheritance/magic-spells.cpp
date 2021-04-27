

  /* Enter your code here */
    Fireball *fbl = dynamic_cast<Fireball*>(spell);
    Frostbite *fbt = dynamic_cast<Frostbite*>(spell);
    Waterbolt *wb = dynamic_cast<Waterbolt*>(spell);
    Thunderstorm *ts = dynamic_cast<Thunderstorm*>(spell);
    
    string name = spell->revealScrollName();
    
    if (fbl) {
        fbl->revealFirepower();
    } else if (fbt) {
        fbt->revealFrostpower();
    } else if (wb) {
        wb->revealWaterpower();
    } else if (ts) {
        ts->revealThunderpower();
    } else if (SpellJournal::journal.length()) {
        //cerr << SpellJournal::journal << endl;
        //cerr << name << endl;
        int l1 = SpellJournal::journal.length();
        int l2 = name.length();
        int size = (l2 + 1) * (l1 + 1);
        int *lcs = new int[size]();
        for (int i = 0; i < size; i++) {
            lcs[i] = 0;
        }
        
        int w = l2 + 1;
        for (int i = 1; i <= l1; i++)
        {
            for (int j = 1; j <= l2; j++) {
                if (SpellJournal::journal[i-1] == name[j-1]) {
                    lcs[i*w + j] = 1 + lcs[(i-1)*w + (j-1)];
                } else {
                    int up = lcs[(i-1)*w + j];
                    int left = lcs[i*w + (j-1)];
                    lcs[i*w + j] = (up > left) ? up : left;
                }
            }
        }
        for (int i = 0; i < l1; i++)
        {
            for (int j = 0; j < l2; j++) {
                //cerr << lcs[i*w + j] << " ";
            }
            //cerr << endl;
        }
        cout << lcs[size-1] << endl;  
    }
    
    /*
Thunderstorm: 48096
6
Frostbite: 67386
5
Waterbolt: 9241
6
Thunderstorm: 64405
18
6
15
    */
    

