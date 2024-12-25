class Tree {

  private:

	const int log2dist;

	vector<int> par;

	vector<vector<int>> pow2ends;


  public:

	Tree(const vector<int> &parents)

	    : log2dist(std::ceil(std::log2(parents.size() + 1))), par(parents.size() + 1),

	      pow2ends(par.size(), vector<int>(log2dist + 1)) {

		par[0] = -1;

		for (int i = 0; i < parents.size(); i++) { par[i + 1] = parents[i]; }


		// pow2ends[n][k] contains the 2^kth parent of node n

		// if there is no 2^kth parent, the value is -1

		for (int n = 0; n < par.size(); n++) { pow2ends[n][0] = par[n]; }

		for (int p = 1; p <= log2dist; p++) {

			for (int n = 0; n < par.size(); n++) {

				int halfway = pow2ends[n][p - 1];

				if (halfway == -1) {

					pow2ends[n][p] = -1;

				} else {

					pow2ends[n][p] = pow2ends[halfway][p - 1];

				}

			}

		}

	}


	/** @return the kth parent of node n */

	int kth_parent(int n, int k) {

		int at = n;

		// break down k into powers of 2 by looping through its bits

		for (int pow = 0; pow <= log2dist; pow++) {

			if ((k & (1 << pow)) != 0) {

				at = pow2ends[at][pow];

				if (at == -1) {

					break;  // stop when we're past the root

				}

			}

		}

		return at;

	}

};