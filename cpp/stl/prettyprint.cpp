

        auto flags = cout.flags();

        cout.setf(ios::hex, ios::basefield);
        cout.setf(ios::showbase);
        cout.unsetf(ios::uppercase);
        cout.width(0);
        cout.precision(0);
        cout << (long)A << endl;
        cout.flags(flags);
        
        //cout << setiosflags(ios::showpos) << setfill('_') << setw(15) << setprecision(2);
        cout.setf(ios::right|ios::showpos|ios::fixed);
        cout.fill('_');
        cout.width(15);
        cout.precision(2);
        cout << B << endl;
        cout.flags(flags);

        cout.setf(ios::scientific | ios::uppercase);
        cout.precision(9);
        cout << C << endl;
        cout.flags(flags);


