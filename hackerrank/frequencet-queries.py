import unittest

def freqQuery(queries):
    mp = {}
    fq_ctr = {}
    for (q, n) in queries:
        if q == 1:
            fq = mp.get(n, 0)
            mp[n] = fq + 1
            ctr_old = fq_ctr.get(fq, 0)
            ctr_new = fq_ctr.get(fq + 1, 0)
            if ctr_old > 0:
                fq_ctr[fq] -= 1
            fq_ctr[fq + 1] = ctr_new + 1
        elif q == 2:
            if mp.get(n,0):
                fq = mp[n]
                mp[n] = fq - 1
                ctr_old = fq_ctr.get(fq, 0)
                ctr_new = fq_ctr.get(fq - 1, 0)
                if ctr_old > 0:
                    fq_ctr[fq] -= 1
                fq_ctr[fq - 1] = ctr_new + 1
        elif q == 3:
            print(1 if fq_ctr.get(n,0) else 0)
        else:
            raise Exception("Invalid query type: {}".format(q))

class TestFreqQuery(unittest.TestCase):

    def test_1(self):
        queries = [(1,5), (1,6), (3,2), (1,10), (1,10), (1,6), (2,5), (3,2)]
        freqQuery(queries)

    def test_2(self):
        queries = [(3,4), (2,1003), (1,16), (3,1)]
        freqQuery(queries)

    def test_3(self):
        queries = [(1,3), (2,3), (3,2), (1,4), (1,5), (1,5), (1,4), (3,2), (2,4), (3,2)]
        freqQuery(queries)

if __name__ == "__main__":
    unittest.main()