# pascalbrAnalise
Análise léxica e sintática para uma versão simplificada de pascal conforme 2ebnfpascalbr.pdf.
Implementada em C conforme diretrizes do livro Conceitos de Linguagens de Programação de Robert W. Sebesta.

<h4>1 - Características da linguagem a serem reconhecidas na análise</h4>
<table>
  <thead>
    <tr>
      <th>Característica</th>
      <th>Status</th>
    </tr>
  <thead>
  <tbody>
    <tr>
      <td>Sentenças de declaração de variáveis dos tipos <b>inteiro e real</b></td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças de atribuição</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças <b>se então senão</b></td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças <b>caso</b></td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças <b>enquanto</b></td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças <b>repita ate</b></td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>Sentenças <b>para</b></td>
      <td>Sim</td>
    </tr>
  <tbody>
</table>

<h4>2 - Palavras reservadas da linguagem</h4>
<table>
  <thead>
    <tr>
      <th>Palavras reservadas</th>
      <th>Nome do TOKEN</th>
      <th>Código do TOKEN</th>
      <th>Status</th>
    </tr>
  <thead>
  <tbody>
    <tr>
      <td>programa</td>
      <td>PROGRAMA_CODE</td>
      <td>61</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>inicio</td>
      <td>INICIO_CODE</td>
      <td>62</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>fim</td>
      <td>FIM_CODE</td>
      <td>63</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>var</td>
      <td>VAR_CODE</td>
      <td>64</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>inteiro</td>
      <td>INT_CODE</td>
      <td>65</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>real</td>
      <td>REAL_CODE</td>
      <td>66</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>se</td>
      <td>SE_CODE</td>
      <td>67</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>entao</td>
      <td>ENTAO_CODE</td>
      <td>68</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>senao</td>
      <td>SENAO_CODE</td>
      <td>69</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>caso</td>
      <td>CASO_CODE</td>
      <td>70</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>escolha</td>
      <td>ESCOLHA_CODE</td>
      <td>71</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>enquanto</td>
      <td>ENQUANTO_CODE</td>
      <td>72</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>faca</td>
      <td>FACA_CODE</td>
      <td>73</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>repita</td>
      <td>REPITA_CODE</td>
      <td>74</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>ate</td>
      <td>ATE_CODE</td>
      <td>75</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>para</td>
      <td>PARA_CODE</td>
      <td>76</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>e</td>
      <td>E_CODE</td>
      <td>77</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>ou</td>
      <td>OU_CODE</td>
      <td>78</td>
      <td>Sim</td>
    </tr>
    <tr>
      <td>nao</td>
      <td>NAO_CODE</td>
      <td>79</td>
      <td>Sim</td>
    </tr>
  <tbody>
</table>
