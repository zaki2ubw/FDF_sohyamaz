#!/bin/bash

# 一時ディレクトリ作成
TMP_DIR=$(mktemp -d)
echo "🔧 作業ディレクトリ: $TMP_DIR"

# Git初期化
cd "$TMP_DIR"
git init -q

# テストファイル作成
touch test.swp

# Gitステータス確認
echo "🔍 git status 結果:"
git status --ignored --short | grep 'test.swp' && echo "✅ 無視されている！" || echo "❌ 無視されていない！"

# クリーンアップ（必要なら）
echo "🧹 後始末は任意で rm -rf $TMP_DIR"

