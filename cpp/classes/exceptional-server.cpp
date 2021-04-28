

		/* Enter your code here. */
        try {
            cout << Server::compute(A, B) << endl;
        } catch (const bad_alloc &e) {
            cout << "Not enough memory" << endl;
        } catch (const exception &e) {
            cout << "Exception: " << e.what() << endl;
        } catch (...) {
            cout << "Other Exception" << endl;
        }

