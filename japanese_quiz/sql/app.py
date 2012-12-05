from flask import *
import sqlite3
from itemquery import ItemQuery

DEBUG = True

app = Flask(__name__)
app.config.from_object(__name__)

@app.route('/')
def deset():
    i = ItemQuery( g.db )
    lista, lista_odgovora = i.query_next_ten()

    pom = (0,0,0,-1,-1,-1,-2,-2,-3,-3)
    lista = [ ( pom[ i[0] ] , i[1] ) for i in enumerate(lista) ]

    return render_template('rad.html', lista = lista,
                                       lista_odgovora = lista_odgovora )


def connect_db():
    return sqlite3.connect('database/jap.db').cursor()

@app.before_request
def before_request():
    g.db = connect_db()



if __name__ == "__main__":
    app.run()
    g.db.close()
