/*
-----------------------------------------------------------------------------------------
		PROJETO SÓCIO-COMUNITÁRIO

Autor: Dhene Arlis Oliveira Cavalcante da Silva

Nome do programa: Sistema de Classificação e Alerta de Consumo de Água Residencial

-----------------------------------------------------------------------------------------
*/



#include <stdio.h>

int main() {
    float leitura_anterior, leitura_atual, consumo;
    float tarifa_agua, tarifa_esgoto, valor_total;
    int num_moradores;

    printf("=== SISTEMA DE ALERTA EMBASA - CONSUMO DE AGUA (BA) ===\n");
    printf("Informe a leitura ANTERIOR do hidrometro (m3): ");
    scanf("%f", &leitura_anterior);
    printf("Informe a leitura ATUAL do hidrometro (m3): ");
    scanf("%f", &leitura_atual);
    printf("Informe o numero de moradores da residencia: ");
    scanf("%d", &num_moradores);

    consumo = leitura_atual - leitura_anterior;

    if (consumo < 0.0f) {
        printf("\nERRO: A leitura atual nao pode ser menor que a anterior.\n");
        return 1;
    }

    if (consumo <= 6.0f) {
        tarifa_agua = 43.23f;
    } else if (consumo <= 10.0f) {
        tarifa_agua = 43.23f + (consumo - 6.0f) * 1.55f;
    } else if (consumo <= 15.0f) {
        tarifa_agua = 43.23f + (4.0f * 1.55f) + (consumo - 10.0f) * 9.81f;
    } else if (consumo <= 20.0f) {
        tarifa_agua = 43.23f + (4.0f * 1.55f) + (5.0f * 9.81f) + (consumo - 15.0f) * 7.54f;
    } else if (consumo <= 30.0f) {
        tarifa_agua = 43.23f + (4.0f * 1.55f) + (5.0f * 9.81f) + (5.0f * 7.54f) + (consumo - 20.0f) * 10.50f;
    } else {
        tarifa_agua = 43.23f + (4.0f * 1.55f) + (5.0f * 9.81f) + (5.0f * 7.54f) + (10.0f * 10.50f) + (consumo - 30.0f) * 14.00f;
    }

    tarifa_esgoto = tarifa_agua * 0.80f;
    valor_total = tarifa_agua + tarifa_esgoto;

    if (consumo <= 10.0f) {
        printf("\n[CLASSIFICACAO: ECONOMICO (ate 10 m3/mes)]\n");
        printf("Dica: Parabens! Consumo dentro da faixa ideal. Mantenha os habitos atuais.\n");
    } else if (consumo <= 20.0f) {
        printf("\n[CLASSIFICACAO: MODERADO (11-20 m3/mes)]\n");
        printf("Dica: Consumo aceitavel. Evite banhos longos e feche torneiras ao escovar os dentes.\n");
    } else if (consumo <= 30.0f) {
        printf("\n[CLASSIFICACAO: ALERTA (21-30 m3/mes)]\n");
        printf("Dica: Consumo elevado. Verifique vazamentos e reduza regas em horarios adequados.\n");
    } else {
        printf("\n[CLASSIFICACAO: CRITICO (acima de 30 m3/mes)]\n");
        printf("Dica: Consumo excessivo! Faca revisao hidraulica urgente e reavalie habitos de consumo.\n");
    }

    printf("\n=== RESUMO DA CONTA EMBASA ===\n");
    printf("Consumo apurado no mes: %.2f m3\n", consumo);
    printf("Valor da agua: R$ %.2f\n", tarifa_agua);
    printf("Taxa de esgoto (80%%): R$ %.2f\n", tarifa_esgoto);
    printf("VALOR TOTAL ESTIMADO: R$ %.2f\n", valor_total);
    
    if (num_moradores > 0) {
        printf("Custo medio por morador: R$ %.2f\n", valor_total / num_moradores);
    }

    printf("\n[AVISO] Valores estimados com base na tabela EMBASA 2026.\n");
    printf("Para valor exato, consulte o site oficial: embasa.ba.gov.br\n");

    return 0;
}
