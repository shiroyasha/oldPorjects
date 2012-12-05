import sqlite3

class ItemQuery:
    def __init__(self, db):
        self.db = db

    def query_items(self, first, last ):
        lista = [0, 1, 2, 3, 4, 5, 6, 7 ] # inicialize list with random elements
        for i in xrange(0, 8):
            lista[i] = self.db.execute('''select value from items where type = ?
                                          and fieldId >= ? and fieldId < ? order by
                                          fieldId ''', ( i , first , last ) 
                                       ).fetchall()

        # transpose, deep magic
        return [ [i,] + [ lista[j][i][0] for j in xrange(0, len(lista)) ] for i in
                xrange( 0, len( lista[1] ) ) ]


    def query_first_not_finished(self):
        return self.db.execute('''select id from exp where percent < 1.0 limit 1
                               ''').fetchall()[0][0]


    def query_next_ten(self):
        group = self.query_first_not_finished() % 100
        lista = self.query_items(group, group + 100)
        
        l1 = [ lista[ len(lista)/ 10 * i ] for i in xrange(0, 10)] 
        l2 = l1 + [ lista[ len(lista)/ 10 * i + 1 ] for i in xrange(0, 10)] 
        return l1, l2


        
        
