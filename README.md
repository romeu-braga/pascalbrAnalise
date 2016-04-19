# pascalbrAnalise
Análise léxica e sintática para uma versão simplificada de pascal.

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
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças de atribuição</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças <b>se então senão</b></td>
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças <b>caso</b></td>
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças <b>enquanto</b></td>
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças <b>repita ate</b></td>
      <td>Não</td>
    </tr>
    <tr>
      <td>Sentenças <b>para</b></td>
      <td>Não</td>
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
      <td>31</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>inicio</td>
      <td>INICIO_CODE</td>
      <td>32</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>fim</td>
      <td>FIM_CODE</td>
      <td>33</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>var</td>
      <td>VAR_CODE</td>
      <td>34</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>inteiro</td>
      <td>INT_CODE</td>
      <td>35</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>real</td>
      <td>REAL_CODE</td>
      <td>36</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>se</td>
      <td>SE_CODE</td>
      <td>37</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>entao</td>
      <td>ENTAO_CODE</td>
      <td>38</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>senao</td>
      <td>SENAO_CODE</td>
      <td>39</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>caso</td>
      <td>CASO_CODE</td>
      <td>40</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>escolha</td>
      <td>ESCOLHA_CODE</td>
      <td>41</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>enquanto</td>
      <td>ENQUANTO_CODE</td>
      <td>42</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>faca</td>
      <td>FACA_CODE</td>
      <td>43</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>repita</td>
      <td>REPITA_CODE</td>
      <td>44</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>ate</td>
      <td>ATE_CODE</td>
      <td>45</td>
      <td>Não</td>
    </tr>
    <tr>
      <td>para</td>
      <td>PARA_CODE</td>
      <td>46</td>
      <td>Não</td>
    </tr>
  <tbody>
</table>

<h4>3 - Lista de exemplos de cada uma das características da linguagem (tabela 1)</h4>
<h5>3.1 - Sentenças de declaração de variáveis dos tipos inteiro e real</h5>
var<br> &nbsp;&nbsp;&nbsp; ate, x, soma, i : integer;<br>&nbsp;&nbsp;&nbsp; sub, k, teste, j : real;
